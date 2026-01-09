#!/bin/bash

result=$(./megaphone "shhhhh... I think the students are asleep...")
echo "$result"

result=$(./megaphone  Damnit " ! " "Sorry students, I thought this thing was off.")
echo "$result"

result=$(./megaphone)
echo "$result"
