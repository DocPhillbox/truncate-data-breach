# truncate-data-breach
 
Truncate a data breach into two files.
This can then be used as two wordlists for a brute-force attack

This version optimizes [TruncatingDatabreach](https://github.com/lurto/TruncatingDatabreach) by writing it in C.
Still faster than [TruncatingDatabreach_V2](https://github.com/lurto/TruncatingDataBreach_V2)

This version truncate 1'000'000 lines in 1.107 seconds, that is 25x times faster.

Example : this will be put into two files
```bash
hello@gmail.com:;Pa$$w0rd
hi@outlook.com:;Pass
man@hotmail:;123456789
woman@icloud.com:;rockyou
hello@gmail.com:;Pa$$w0rd
hi@outlook.com:;Pass
man@hotmail:;123456789
woman@icloud.com:;rockyou
hello@gmail.com:;Pa$$w0rd
hi@outlook.com:;Pass
man@hotmail:;123456789
woman@icloud.com:;rockyou
hello@gmail.com:;Pa$$w0rd
hi@outlook.com:;Pass
man@hotmail:;123456789
woman@icloud.com:;rockyou
hello@gmail.com:;Pa$$w0rd
hi@outlook.com:;Pass
man@hotmail:;123456789
woman@icloud.com:;rockyou
hello@gmail.com:;Pa$$w0rd
hi@outlook.com:;Pass
man@hotmail:;123456789
woman@icloud.com:;rockyou
hello@gmail.com:;Pa$$w0rd
hi@outlook.com:;Pass
man@hotmail:;123456789
woman@icloud.com:;rockyou
hello@gmail.com:;Pa$$w0rd
hi@outlook.com:;Pass
man@hotmail:;123456789
```
