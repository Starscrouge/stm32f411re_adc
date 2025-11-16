# STM32F4 Bare-Metal Project

## Target

- MCU: **STM32F411RE** (change this if different)
- Toolchain: STM32CubeIDE (GCC)

## Dependencies

This project **does not** include the STM32 device headers or HAL/CMSIS libraries.

You must have **STM32CubeF4** installed. In CubeIDE, install the F4 firmware package and make sure the following include paths are added in the project settings:

- `<STM32CubeF4>/Drivers/CMSIS/Include`
- `<STM32CubeF4>/Drivers/CMSIS/Device/ST/STM32F4xx/Include`

The header `stm32f4xx.h` is taken from the STM32CubeF4 package (path above), not from this repository.

## Building

1. Open the project in **STM32CubeIDE**.
2. Confirm the correct MCU and clock configuration.
3. Ensure the include paths above are configured.
4. Build the project (Project → Build).

## Notes

- Build folders (`Debug`, `Release`) are intentionally ignored by git.
- Only source (`Src`, `Inc`, `Startup`) and project files are tracked.
