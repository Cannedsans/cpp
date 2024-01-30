// Bibliotecas (os arquivos vem da mesma biblioteca)
#include <ThreeWire.h>
#include <RtcDS1302.h>

// Pinos do RTC
#define DS1302_RST  3
#define DS1302_DAT  4
#define DS1302_CLK  5

// Instância da ligação e do RTC
ThreeWire ligacao(DS1302_DAT, DS1302_CLK, DS1302_RST);
RtcDS1302<ThreeWire> rtc(ligacao);

void setup ()
{
  // Inicia a comunicação serial
  Serial.begin(9600);

  // Inicia a comunicação com o RTC
  rtc.Begin();

  // Desabilita a proteção contra escrita para gravar a hora e data
  if (rtc.GetIsWriteProtected())
  {
    rtc.SetIsWriteProtected(false);
  }

  // Se não estava rodando, começa a funcionar
  if (!rtc.GetIsRunning())
  {
    rtc.SetIsRunning(true);
  }

  // Obtém o valor da hora quando o código foi compilado
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  rtc.SetDateTime(compiled);
  // Para definir um formato personalizado, você pode fazer o seguinte:
  // O mês precisa ter 3 letras abreviando o nome do mês em inglês (no exemplo abaixo é fevereiro)
  //RtcDateTime teste = RtcDateTime("Feb 12 2022", "19:32:45");
  //rtc.SetDateTime(teste);
}

void loop ()
{
  // Obtem a data e hora e imprime os valores
  RtcDateTime now = rtc.GetDateTime();

  Serial.print(now.Day());
  Serial.print("/");
  Serial.print(now.Month());
  Serial.print("/");
  Serial.println(now.Year());

  Serial.print(now.Hour());
  Serial.print(":");
  Serial.print(now.Minute());
  Serial.print(":");
  Serial.println(now.Second());

  // Dia da semana (1 a 7, sendo 1 = segunda e 7 = domingo)
  Serial.println(now.DayOfWeek());

  delay(5000);
}
