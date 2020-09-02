package com.example.expr;

public class Constant implements Expression {
    private final int value;

    public Constant (int value){
	this.value = value;
    }

    public int evaluate () { return value; }
    public String toString () { return String.valueOf(value); }
}
