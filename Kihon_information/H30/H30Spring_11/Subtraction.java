//package com.example.test;

import com.example.expr.BinaryOperatorExpression;
import com.example.expr.Expression;

public class Subtraction extends BinaryOperatorExpression {
    public Subtraction (Expression left, Expression right) {
	super(left, right);
    }
    public int evaluate () {
	return getLeft().evaluate() - getRight().evaluate();
    }
    public String getOperator () {
	return "-";
    }
}
