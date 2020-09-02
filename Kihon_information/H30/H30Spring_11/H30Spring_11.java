//package com.example.test;

import com.example.expr.Addition;
import com.example.expr.Constant;
import com.example.expr.Expression;

public class H30Spring_11 {
    public static void main(String[] args){
	Expression two = new Constant(2);
	Expression five = new Constant(5);
	Expression add = new Addition(two, five);
	//System.out.println(add + " = " + add.evaluate());
	System.out.println(new Subtraction(add, new Subtraction(two, five)));
    }
}
