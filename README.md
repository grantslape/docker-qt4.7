# gui-intro
Intro to GUI with QT 4.7 and OpenGL

QT 4.7 is a pain to install - luckily this `Dockerfile` should take care of everything for you in that regard.

## Setup
You could have other projects in subdirectories under `app/`.  Just pass in the build directory as the `BUILDDIR` arg:

```shell
docker build . -t qt --build-arg BUILDDIR=spin-slide
```

## Usage
You'll need to set up X11 Forwarding.  On MacOS I used [this article](https://cntnr.io/running-guis-with-docker-on-mac-os-x-a14df6a76efc).  Here is the short version of the set up from the article:

```shell
brew install socat
brew cask install xquartz
```

**!!IMPORTANT!!**
**You need to log out of MacOS before proceeding!**

Then open Xquartz and enable *allow connections from network clients*.

```shell
open -a Xquartz
```

Leave Socat running in a shell:

```shell
socat TCP-LISTEN:6000,reuseaddr,fork UNIX-CLIENT:\"$DISPLAY\"
```

Get your *inet* IP address:

```shell
ifconfig en0
```

Start up the container, (with subproject path if needed):

```shell
docker run -e DISPLAY=IP_ADDRESS:0 qt:latest
```

