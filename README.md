# TEST Pidgin Plugin, Please Ignore

Replaces an EFT formatted fit with an o.smium.org link to the fit.

# Usage

Simply paste an EFT fit in a chat room (no IMs for now) and send it. The message actually sent will be an o.smium.org link with the request /loadout/dna/[dna]. If you want to bypass the plugin and send the actual EFT formatted fit, add a whitespace before the fit (right before the '[' in the first line).

# Installation

Drop testplugin.dll in %APPDATA%/.purple/plugins and activate the plugin in Pidgin. If you have an older version installed, you need to close pidgin before replacing the .dll.

# FAQ

- It doesn't work! ...?

First, reset your font formatting (click font > reset formatting). 

Second, test it with a slasher fit (there might be some ships not recognized by the parser).

If that doesn't solve the problem, open the debug window (help > debug window), select 'info' in the level droplist, write 'core-test' in the filter box and select filter. Then save the debug info and attach it to your bug report (you can open an issue here or contact me through the forums or jabber).
