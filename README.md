# E-paper_display_library_for_EFR32
This is a E-paper display library for Silicon Labs EFR32 series microcontrollers. This library is for Waveshare 1.54 inch 200x200 E-paper display.

This project uses Silicon Labs EFR32MG12 Mighty Gecko kit. I have used BRD4162A (EFR32MG12P332F1024GL125) in this project. To import this project you should have Gecko Suite v2.4 installed. Copy the .sls file to a folder on desktop. Then goto File->Import. Give that folder path it will automatically detect the project. Click Next->Next->Finish. Build and then run the project.

For wiring I have used:

=> CLK --> PA8
=> CS --> PA9
=> MOSI --> PA6
=> MISO --> PA7   (N/A)
=> BUSY --> PD10
=> DC --> PD8
=> RESET --> PD9

All these pins are available on the Expansion Header of the board. For help you can visit:
https://www.silabs.com/documents/public/user-guides/ug261-brd4162a.pdf


I have used the following library and converted it to be used with Silicon Labs Simplicity Studio IDE:
https://github.com/ZinggJM/GxEPD


The above library also uses the following Adafruit GFX Library. So I have used and converted some of the files of this too.
https://github.com/adafruit/Adafruit-GFX-Library


You can also add most of the fonts to the e-paper display. Follow the following link to add new fonts. Font files should have ttf extension.
https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts


The variable FONT_WIDTH should have to be set manually according to the font size.
