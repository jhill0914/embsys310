# Embedded System Challenges

The embedded system that I would like to discuss is a fitness tracking device, such as a FitBit.  In a very small package, it incorporates a display, an accelerometer, a heart rate monitor, a battery, and in some cases a GPS tracking chip.  It also must store fitness data for a time until it is able to synchronize with a mobile phone or computer.

There are several things that I can think of that would make it challenging to develop a device like the FitBit:

*  Physical size was likely a significant challenge.  Incorporating the required sensors, as well as a display, a microprocessor and storage in such a small package would be very difficult.  Fortunately, modern electronics keep shrinking, leading to increased capabilities in smaller packages
*  Data processing algorithms would be another challenge.  The FitBit detects not only steps taken, but also flights of stairs, distance travelled, calories burned, and amount of time spent being active.  Some of those are simple calculations, but reliably detecting steps without false positives would require some interesting pattern recognition code.  I imagine that detecting increasing elevation (flights of stairs) would also require some interesting calculations

Other challenges:

*  Data storage:  activity and fitness data must be stored until able to sync
*  Reliability:  as a consumer device, the software must be robust and reliable
*  Debuggability:  there is a debug interface (USB), but again as a consumer device a programmer will not have access to it as it is having issues.  The device must report status in a way that helps customer support troubleshoot it
*  Power consumption:  as a small device, it will have a small battery.  Power consumption must be strictly constrained to get the maximum life possible from the battery
*  Software updates:  updates to firmware must be made available to the customer to download and load onto the device
*  Cost:  consumer devices are extremely competitive, cost wise.  Cost must be kept to a minimum, while also providing the needed functionality
