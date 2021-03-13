# Kudo Disk Operating System

An OS and Kernel Project for Learning Purposes based on Nasm and x86_64 which implements C and C++ code for kernel functionality

## Building .iso and /dist

Since this project was made based on the series of davidcallanan the standard build process will also
use docker and a container for utilising the compilers for assembly and C/C++. It can also be simply built 
on Linux or Windows but for ease docker is used since it can provide quick and simply virtualisation 
features that make building it rather easy.

```bash
docker build ./buildenv -t kudos-build  
```

### Entering the shared container

 - Linux or MacOS: `docker run --rm -it -v "$pwd":/root/env kudos-build`
 - Windows (CMD): `docker run --rm -it -v "%cd%":/root/env kudos-build`
 - Windows (PowerShell): `docker run --rm -it -v "${pwd}:/root/env" kudos-build`
 - NOTE: If you are having trouble with an unshared drive, ensure your docker daemon has access to the drive you're development environment is in. 
   For Docker Desktop, this is in "Settings > Shared Drives" or "Settings > Resources > File Sharing".

### Using the Makefile for running the compilers

```bash
make build-x86_64
```
