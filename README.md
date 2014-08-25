8086sample
==========

Sample programs for implementing 8086 emulator

ovtest.cpp : Check overflow with signed add/sub
>a.out -s sub : for subtract
>a.out        : for add

jnl.cpp : Check jnl flag condition with signed compare
>make jnltest

It creates two logfiles and run diff with them
