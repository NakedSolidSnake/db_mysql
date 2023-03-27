# MySQL abstraction

Sets layer on top mysql library to make easy to use.

## Build
This library contains all of its structure inside a container. To build application you can install the tools and libraries directly in your machine. Check Dockerfile and conanfile for dependencies.

### Build using docker-compose
First of all, it is necessary to build image through docker-compose tool

```bash
$ docker-compose build
```
After build, run docker-compose

```bash
$ docker-compose up -d
```

Access the devolpment container
```bash
$ docker container exec -it development bash
```

Inside container install all dependencies
```bash
$ mkdir build
$ cd build
$ conan install ..
```

Run cmake e compile
```bash
$ cmake ..
$ make 
```

Run Test
```bash
$ make test
```
