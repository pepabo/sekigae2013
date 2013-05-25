## Mac OSX Kernel Extension 

```
$ sudo kextload Sekigae.kext
$ sudo cat /var/log/kernel.log

May 25 12:10:53 hibomac kernel[0]: Sekigae has started.
May 25 12:10:53 hibomac kernel[0]: okkun
May 25 12:10:53 hibomac kernel[0]: kitak
May 25 12:10:53 hibomac kernel[0]: keoken
May 25 12:10:53 hibomac kernel[0]: gussan

$ sudo kextunload Sekigae.kext
May 25 12:13:29 hibomac kernel[0]: Sekigae has stopped.
```
