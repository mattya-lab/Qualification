import java.util.Stack;
import java.util.HashMap;
import java.util.Map;

interface Key{
    public void operateOn(Stack<Integer> stack);
}

enum DigitKey implements Key{
    DIGIT0, DIGIT1, DIGIT2, DIGIT3, DIGIT4,
    DIGIT5, DIGIT6, DIGIT7, DIGIT8, DIGIT9;
    public void operateOn(Stack<Integer> stack){
	stack.push(stack.pop() * 10 + ordinal());
    }
}

enum OperationKey implements Key{
    ADD, SUBTRACT, MULTIPLY, DIVIDE, EQUAL, CLEAR;
    public void operateOn(Stack<Integer> stack){
	if(this == EQUAL || this==CLEAR){
	    return ;
	}
	int val2 = stack.pop();
	int val1 = stack.pop();
	stack.push(calculate(val1, val2));
    }
    private int calculate(int val1, int val2){
	switch(this){
	case ADD: return val1 + val2;
	case SUBTRACT: return val1 - val2;
	case MULTIPLY: return val1 * val2;
	case DIVIDE: return val1 / val2;
	default : throw new AssertionError(toString());
	}
    }
}

class Calculator{
    private final Stack<Integer> stack = new Stack<Integer>();
    private Key pendingKey;

    public Calculator(){
	stack.push(0);
    }

    public void onKeyPressed(Key key){
	System.out.println(key);
	if (key instanceof DigitKey){
	    if (pendingKey == OperationKey.EQUAL) {
		reset();
	    }
	    key.operateOn(stack);
	    System.out.println(stack.peek());
	} else if (key == OperationKey.CLEAR) {
	    reset();
	    System.out.println(stack.peek());
	} else {
	    try {
		if (pendingKey != null) {
		    pendingKey.operateOn(stack);
		}
		System.out.println(stack.peek());
		pendingKey = key;
		if (key != OperationKey.EQUAL) {
		    stack.push(0);
		}
	    } catch (ArithmeticException e){
		System.out.println("Error");
		reset();
	   }
	}
    }
    private void reset() {
	stack.clear();
	stack.push(0);
	pendingKey = null;
    }	    
}

public class H28Autumn_11{
    // command java H28Autumn_11 -> " " ->
    // (1) 2*6/3=, (2) -2=, (3) 2*4==, (4) 2*4C2=, (5) 8/2/= 
    public static void main(String[] args){
	Map<Character, Key> map = new HashMap<Character, Key>();
	for (OperationKey key : OperationKey.values())
	    map.put("+-*/=C".charAt(key.ordinal()), key);
	for(DigitKey key : DigitKey.values())
	    map.put("0123456789".charAt(key.ordinal()), key);

	Calculator calc = new Calculator();
	String chars = args[0];
	for(int i = 0; i < chars.length(); i++){
	    calc.onKeyPressed(map.get(chars.charAt(i)));
	}
    }
}
