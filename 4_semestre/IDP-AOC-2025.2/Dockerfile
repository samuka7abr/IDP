FROM debian:stable-slim

RUN dpkg --add-architecture riscv64

RUN apt update && \
    apt install -y \
      gcc-riscv64-linux-gnu \
      binutils-riscv64-linux-gnu \
      qemu-user \
      build-essential \
      nano \
      vim && \
    apt clean

RUN useradd -ms /bin/bash riscv
USER riscv
WORKDIR /home/riscv

CMD ["/bin/bash"]
