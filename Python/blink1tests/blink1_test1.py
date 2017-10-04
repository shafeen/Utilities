#!/usr/bin/env python

"""
blink1_tst -- simple demo of blink1 library

You can also just run blink1_pyusb.py as a blink1-tool replacement

"""

from blink1lib.blink1 import Blink1, Blink1Pattern
import time



def basicFade():
    blink1 = Blink1()

    if blink1.dev is None:
        print("no blink1 found")
    else:
        print "blink(1) found"

    print "serial number: " + blink1.get_serialnumber()
    print "firmware version: " + blink1.get_version()

    print "fading to #ffffff"
    blink1.fade_to_rgb( 1000, 255,255,255)

    time.sleep(0.5)

    print "fading to #000000"
    blink1.fade_to_rgb( 1000, 0,0,0)

    print "done"


# example string: '10, #aa0a0a, .2 ,#000000, .2'
def playSimplePattern(patternStr):
    blink1 = Blink1()
    blinkPattern = Blink1Pattern.parse_pattern_string(patternStr)
    print blinkPattern.colors, blinkPattern.times, blinkPattern.repeats
    print "playing pattern: "+ str(blinkPattern)
    for i in range(blinkPattern.repeats):
        for j in range(len(blinkPattern.colors)):
            color = blinkPattern.colors[j]
            millis = int( blinkPattern.times[j] * 1000 )
            print "color: "+str(color) +", millis: "+ str(millis)
            blink1.fade_to_rgb( millis/2, color[0], color[1], color[2])
            time.sleep( millis / 1000.0 )

playSimplePattern('5, #aa0a0a, .3 ,#000000, .3')
