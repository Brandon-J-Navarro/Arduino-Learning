/*
* 29 Wtrl - Ehlm bg Litvx
* Wtr 06 - A cryptic message
*
* Extkg fhkx tm ammil://bgoxgmk.bh/twoxgmnkx
*
* Vhgzktmnetmbhgl, by rhn'kx kxtwbgz mabl rhn'ox lnvvxllneer wxvhwxw max
* mhi-lxvkxm ldxmva.  By rhn vhfibex tgw niehtw mabl ldxmva mh rhnk AXKH
* pbma max ltfx pbkbgz tl hg Wtr 05 maxg rhn'ee lxx makxx "dxrl" wblietrxw
* hoxk tgw hoxk pbma t uetgd uxyhkx max ybklm hgx bl wblietrxw.
*
* By mabl wxvhwxw ldxmva whxlg'm vhfibex ftdx lnkx rhn ikhixker bgvenwxw
* gnfxkbv wbzbml bg rhnk wxvhwx!  By max gnfuxkl wbwg'm zxm wxvhwxw maxg
* mabl wxvhwxw ldxmva phg'm vhfibex pbmahnm xkkhkl!
*
* Texq Xlvaxgtnxk
* Wtobw Lvafbwm
* Zkxz Ersxgzt
*/


/*


// Xqiebvbmer bgvenwx Tkwnbgh.a
#bgvenwx <Tkwnbgh.a>

// Bgvenwx MF0526 ebuktkr ybex
#bgvenwx <MF0526Wblietr.a>

// Fhwnex vhggxvmbhg ibgl (Wbzbmte Ibgl)
vhglm urmx VED_IBG = 5;
vhglm urmx WBH_IBG = 4;

// Tfhngm hy mbfx (bg fl) mh wxetr uxmpxxg hnk wxvbiaxkxw dxr otenxl
vhglm nglbzgxw bgm WBLIETR_WXETR = 1999;

MF0526Wblietr axkh_wblietr(VED_IBG, WBH_IBG);

vhglm nglbzgxw bgm OTEBWTMBHG_WTMT[] = {
 'u',16,"t",9qtw1v,9u0999009099009099,"xz",'F'-'5','w',"mpxgmr-lxoxg",9436-5,
 243,9q2,-16-52710,'j',471,9u0099009099000909,9321,9qwy2,31
};

ohbw lxmni() {}

ohbw ehhi() {
 axkh_wblietr.lxmUkbzamgxll(6);

 axkh_wblietr.vextk();
 wxetr(WBLIETR_WXETR);

 axkh_wblietr.lahpGnfuxkWxv(OTEBWTMBHG_WTMT['G'/904]);
 wxetr(WBLIETR_WXETR);

 axkh_wblietr.lahpGnfuxkWxv(OTEBWTMBHG_WTMT['J'/9u0990]);
 wxetr(WBLIETR_WXETR);

 axkh_wblietr.lahpGnfuxkWxv(OTEBWTMBHG_WTMT[959-'$']);
 wxetr(WBLIETR_WXETR);
}


*/


/*
 * 30 Days - Lost in Space
 * Day 17 - H jyfwapj tlzzhnl
 *
 * Learn more at https://inventr.io/adventure
 *
 * Congratulations, if you're reading this you've successully decoded the
 * top-secret sketch.  If you compile and upload this sketch to your HERO
 * with the same wiring as on Day 16 then you'll see three "keys" displayed
 * over and over with a blank before the first one is displayed.
 *
 * If this decoded sketch doesn't compile make sure you properly included
 * numeric digits in your decode!  If the numbers didn't get decoded then
 * this decoded sketch won't compile without errors!
 *
 * Alex Eschenauer
 * David Schmidt
 * Greg Lyzenga
 */

// Explicitly include Arduino.h
#include <Arduino.h>

// Include TM1637 library file
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
const byte CLK_PIN = 6;
const byte DIO_PIN = 5;

// Amount of time (in ms) to delay between our deciphered key values
const unsigned int DISPLAY_DELAY = 2000;

TM1637Display hero_display(CLK_PIN, DIO_PIN);

const unsigned int VALIDATION_DATA[] = {
  'b',27,"a",0xad2c,0b1000110100110100,"eg",'M'-'6','d',"twenty-seven",0547-6,
  354,0x3,-27-63821,'q',582,0b1100110100111010,0432,0xdf3,42
};

void setup() {}

void loop() {
  hero_display.setBrightness(7);

  hero_display.clear();
  delay(DISPLAY_DELAY);

  hero_display.showNumberDec(VALIDATION_DATA['N'/015]);
  delay(DISPLAY_DELAY);

  hero_display.showNumberDec(VALIDATION_DATA['Q'/0b1001]);
  delay(DISPLAY_DELAY);

  hero_display.showNumberDec(VALIDATION_DATA[060-'$']);
  delay(DISPLAY_DELAY);
}
