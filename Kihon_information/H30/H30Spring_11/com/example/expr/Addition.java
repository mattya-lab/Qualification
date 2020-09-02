package com.example.expr;

public class Addition implements Expression {
    private final Expression left, right;

    public Addition (Expression left, Expression right){
	if(left == null || right == null){
	    throw new NullPointerException();
	}
	this.left = left;
	this.right = right;
    }

    public int evaluate () {
	return left.evaluate() + right.evaluate();
    }

    public String toString () {
	return String.format("(%s + %s)", left, right);
    }
}
