[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver TPL0501

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/tpl0501/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE) 

Das TPL0501-Gerät ist ein einkanaliges, lineares digitales Potentiometer mit 256 Schleiferpositionen. Dieses Gerät kann als Potentiometer mit drei Anschlüssen oder als Rheostat mit zwei Anschlüssen verwendet werden. Das TPL0501 wird derzeit mit einem End-zu-End-Widerstand von 100 kΩ angeboten. Auf die internen Register des TPL0501 kann über eine SPI-kompatible Schnittstelle zugegriffen werden. Das TPL0501 hat einen nominalen Temperaturkoeffizienten von 35 ppm/°C.

LibDriver TPL0501 ist der voll funktionsfähige Treiber von TPL0501, der von LibDriver eingeführt wurde. Er bietet eine digitale Potentiometerfunktion. LibDriver ist MISRA-kompatibel.

### Inhaltsverzeichnis

  - [Anweisung](#Anweisung)
  - [Installieren](#Installieren)
  - [Nutzung](#Nutzung)
    - [example basic](#example-basic)
  - [Dokument](#Dokument)
  - [Beitrag](#Beitrag)
  - [Lizenz](#Lizenz)
  - [Kontaktieren Sie uns](#Kontaktieren-Sie-uns)

### Anweisung

/src enthält LibDriver TPL0501-Quelldateien.

/interface enthält die plattformunabhängige Vorlage LibDriver TPL0501 SPI.

/test enthält den Testcode des LibDriver TPL0501-Treibers und dieser Code kann die erforderliche Funktion des Chips einfach testen.

/example enthält LibDriver TPL0501-Beispielcode.

/doc enthält das LibDriver TPL0501-Offlinedokument.

/Datenblatt enthält TPL0501-Datenblatt.

/project enthält den allgemeinen Beispielcode für Linux- und MCU-Entwicklungsboards. Alle Projekte verwenden das Shell-Skript, um den Treiber zu debuggen, und die detaillierten Anweisungen finden Sie in der README.md jedes Projekts.

/misra enthält die Ergebnisse des LibDriver MISRA Code Scans.

### Installieren

Verweisen Sie auf eine plattformunabhängige SPI-Schnittstellenvorlage und stellen Sie Ihren Plattform-SPI-Treiber fertig.

Fügen Sie das Verzeichnis /src, den Schnittstellentreiber für Ihre Plattform und Ihre eigenen Treiber zu Ihrem Projekt hinzu. Wenn Sie die Standardbeispieltreiber verwenden möchten, fügen Sie das Verzeichnis /example zu Ihrem Projekt hinzu.

### Nutzung

Sie können auf die Beispiele im Verzeichnis /example zurückgreifen, um Ihren eigenen Treiber zu vervollständigen. Wenn Sie die Standardprogrammierbeispiele verwenden möchten, erfahren Sie hier, wie Sie diese verwenden.

#### example basic

```C
#include "driver_tpl0501_basic.h"

uint8_t res;
float wl_ohm;
float hw_ohm;
float percentage = 50.0f;

/* init */
res = tpl0501_basic_init();
if (res != 0)
{
    return 1;
}

...
    
/* write data */
res = tpl0501_basic_write(percentage, &wl_ohm, &hw_ohm);
if (res != 0)
{
    (void)tpl0501_basic_deinit();

    return 1;
}

/* output */
tpl0501_interface_debug_print("tpl0501: percentage is %0.2f%%.\n", percentage);
tpl0501_interface_debug_print("tpl0501: wl is %0.2fohm.\n", wl_ohm);
tpl0501_interface_debug_print("tpl0501: hw is %0.2fohm.\n", hw_ohm);

...
    
/* deinit */
(void)tpl0501_basic_deinit();

return 0;
```

### Dokument

Online-Dokumente: [https://www.libdriver.com/docs/tpl0501/index.html](https://www.libdriver.com/docs/tpl0501/index.html).

Offline-Dokumente: /doc/html/index.html.

### Beitrag

Bitte beachten Sie CONTRIBUTING.md.

### Lizenz

Urheberrechte © (c) 2015 - Gegenwart LibDriver Alle Rechte vorbehalten



Die MIT-Lizenz (MIT)



Hiermit wird jeder Person kostenlos die Erlaubnis erteilt, eine Kopie zu erhalten

dieser Software und zugehörigen Dokumentationsdateien (die „Software“) zu behandeln

in der Software ohne Einschränkung, einschließlich, aber nicht beschränkt auf die Rechte

zu verwenden, zu kopieren, zu modifizieren, zusammenzuführen, zu veröffentlichen, zu verteilen, unterzulizenzieren und/oder zu verkaufen

Kopien der Software und Personen, denen die Software gehört, zu gestatten

dazu eingerichtet werden, unter folgenden Bedingungen:



Der obige Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen enthalten sein

Kopien oder wesentliche Teile der Software.



DIE SOFTWARE WIRD "WIE BESEHEN" BEREITGESTELLT, OHNE JEGLICHE GEWÄHRLEISTUNG, AUSDRÜCKLICH ODER

STILLSCHWEIGEND, EINSCHLIESSLICH, ABER NICHT BESCHRÄNKT AUF DIE GEWÄHRLEISTUNG DER MARKTGÄNGIGKEIT,

EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL DARF DAS

AUTOREN ODER URHEBERRECHTSINHABER HAFTEN FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE

HAFTUNG, OB AUS VERTRAG, DELIKT ODER ANDERWEITIG, ENTSTEHEND AUS,

AUS ODER IM ZUSAMMENHANG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN HANDLUNGEN MIT DER

SOFTWARE.

### Kontaktieren Sie uns

Bitte senden Sie eine E-Mail an lishifenging@outlook.com.