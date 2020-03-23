FROM   ubuntu

RUN apt update && apt upgrade -y
RUN apt install -y build-essential cmake

COPY . /source

RUN mkdir /source/build

WORKDIR /source/build
RUN cmake -- -j 4 .. && make && cp src/normal_chicken / && rm -r /source

ENTRYPOINT ["/normal_chicken"]