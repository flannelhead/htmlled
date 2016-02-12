# HtmlLED
A simple example of building a HTML based UI for a ESP8266 powered device.
This is based on programming the ESP8266 with the Arduino IDE.

## Why?
I've been toying with the idea of a standalone ESP8266-based robot which
would be controlled via a mobile phone browser over WiFi. In the Arduino
world it seems that Bluetooth is a more traditional means of controlling
such appliances. However, in principle, one needs to write a specialised
mobile app to have a nice control interface. It also means the app won't be
cross-platform.

I don't know mobile app development well. What I know better is JavaScript and
HTML. So I set out to have the ESP8266 act as a WiFi access point (and hence not
depend on any existing WiFi network) and serve its own control UI to the phone
browser. Neat, isn't it?

While there's a wealth of ESP8266 examples around, I didn't find an application exactly
like mine by a quick glance. This wasn't hard to implement, but there are some
pitfalls. Hence I've shared this example with you.

My requirements for this system were:

* Be standalone. The device mustn't depend on any existing network.
* Two-way communication between client and the device.
* HTML and JS files stored in the [SPIFFS](https://github.com/esp8266/Arduino/blob/master/doc/filesystem.md) for scalability.
In most examples the HTML files were "baked in" the source code.
* No unnecessary page loads -- implement user interaction as AJAX calls.

## How to use this?
These files are meant to be used with the Arduino IDE and the [ESP8266 core](https://github.com/esp8266/Arduino).
At the time of writing Arduino 1.6.7 was used with the most recent [git checkout](https://github.com/esp8266/Arduino#using-git-version-)
of the ESP8266 core due to some problems regarding the stable version.

Open `htmlled.ino` in the Arduino IDE. Select the ESP8266 board you're using and
flash the sketch.

`index.html` (and any other files) must be compiled into a SPIFFS filesystem and
uploaded to the board. There's good [documentation](https://github.com/esp8266/Arduino/blob/master/doc/filesystem.md)
on the subject. For small projects it makes sense to choose the 1M SPIFFS size (or smaller if available) to
avoid unnecessarily long upload times.

The sketch was tested on a [WeMos Mini D1](http://www.wemos.cc/wiki/doku.php?id=en:d1_mini).

## Contributions
While this is meant to be a simplistic example, there's always room for improvement.
Pull requests are appreciated. There are some items I intend to tackle:

* Diagnostic information over serial
* Seamless support for serving multiple files (such as CSS, JS and images)

