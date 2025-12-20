# EXERCISES

## EX 1
- load n signed integers from memory, compute the sum and store in memory

## EX2
- count how many times 'a' (0x61) appears in the first N bytes of buf

## CHALLENGE 1
- given an array of packed records that are:
```
offset 0: int32 id
offset 4: int16 grade (signed)
offset 6: uint8 flags
offset 7: uint8 pad
sizeof(arr) = 8 bytes
```
- compute the sum off all grades accros M records if their flag bit is equal to 0x0 and store it in a 32-bit word

## CHALLENGE 2
- copy len bytes from src to dst using only byte loads/stores


## CHALLENGE 3?
- how can i make memcpy faster?
