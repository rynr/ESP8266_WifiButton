WifiButton
==========

This code is meant to be put into an
[ESP8266](https://de.wikipedia.org/wiki/ESP8266). It should send a message to a
central service that can decide on what to do with the information.

Sequence
--------

At boot (or reset) the Chip connects to the WiFi and sends a MQTT-message to a
defined host. Then it goes to deep sleep so that it does not need any more
energy. Hopefully it will not need that much energy that it can easily be run
with a battery.

Links
-----


 - [Info](https://rynr.github.io/ESP8266_WifiButton/)
 - [Github](https://github.com/rynr/ESP8266_WifiButton)
 - [Bugs](https://github.com/rynr/ESP8266_WifiButton/issues)
 - [![Build Status](https://travis-ci.org/rynr/ESP8266_WifiButton.svg?branch=master)](https://travis-ci.org/rynr/ESP8266_WifiButton)
