# learn-cpp

Working through [learncpp.com](https://www.learncpp.com/), one lesson a day, no skipped days.

- `tracker/` is `lesson`, a small C++ tool that logs each finished lesson and nags you on any day you haven't logged one.
- Everything else in the repo is stuff I build along the way.

## Tracker

Progress lives in `tracker/progress.log` and syncs between machines through git. `lesson done` commits and pushes it. `lesson check` fetches first, so a lesson finished on one machine counts on the other.

### Install

**Mac** (needs Xcode Command Line Tools: `xcode-select --install`):
```sh
./tracker/install-mac.sh
```

**Windows** (needs Visual Studio with "Desktop development with C++", plus Git for Windows). Run this from *Developer PowerShell for VS* (use an admin window if it says "Access is denied"):
```powershell
powershell -ExecutionPolicy Bypass -File tracker\install-windows.ps1
```

Both scripts build the tool and put `lesson` on your PATH. They also schedule `lesson check` to run at login and at 12:00, 18:00, 20:00, 21:00, 22:00 and 23:00. If nothing is logged for today, `lesson check` pops up an alert. Re-run the script after pulling changes to the tool.

### Use

```sh
lesson done 1.3 "printed my first variable"   # log a lesson (ID from learncpp.com)
lesson                                        # today, streak, best, missed days
lesson log 20                                 # recent history
```

Lesson IDs look like `1.3`, `4.x` or `A.1`. Logging the same lesson twice is rejected because re-reading doesn't count. The day rolls over at local midnight.

### Uninstall

- Mac: `launchctl bootout gui/$(id -u)/com.learncpp.lesson && rm ~/Library/LaunchAgents/com.learncpp.lesson.plist`
- Windows: `Unregister-ScheduledTask learncpp-lesson-check`
