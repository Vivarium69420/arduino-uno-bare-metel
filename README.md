<!-- markdownlint-disable MD025 -->

# Arduino Uno Bare Metal

- Simple program to write code directly with the AVR microcontroller
without the help of Arduino IDE.

<!--toc:start-->
- [Arduino Uno Bare Metal](#arduino-uno-bare-metal)
  - [Dependencies](#dependencies)
<!--toc:end-->

---

# Dependencies

```bash
yay -S avrdude avr-gcc avr-libc
```

- If you are using neovim with clangd as the language server,
please find where the avr-libc includes are and add it to the `.clangd`
so it doesn't scream at you.

```.clangd
CompileFlags:
  Add: [-I/usr/avr/include]
```

---

# Explanation

## Hello World

- We create a simple blink for the builtin LED on PORTB5 by configuring The Port B Data Direction Register (DDRB) at bit 5 to output high (1), similarly we set The Port B Data Register at bit 5 to output high (1) and output low (0) to toggle the light.

## Timer/Counter1 Interrupt

- We create a simple blink but using interrupt and timer
