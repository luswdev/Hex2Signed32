# Hex2Signed32
Turn input hex string into dec signed integer base on 2's complement.

## Types
- Default using C:

```bash
make run
```

- or using target `c`

```bash
make c
```

- Also provide C++:

```bash
make cpp
```

### Flags
- using **HACKED** to using casting method.
- add `-D HACKED` on line 17 in *makefile*

```makefile
CFLAG=-D HACKED
```
