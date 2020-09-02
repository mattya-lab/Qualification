package com.example.expr;

public abstract class BinaryOperatorExpression implements Expression {
    private final Expression left, right;

    protected BinaryOperatorExpression (Expression left, Expression right) {
	if(left == null || right == null) {
	    throw new NullPointerException();
	}
	this.left = left;
	this.right = right;
    }
    protected Expression getLeft () { return left; }
    protected Expression getRight () { return right; }
    protected abstract String getOperator();

    public String toString () {
	return String.format("(%s %s %s)",
			     getLeft(), getOperator(), getRight());
    }
}
