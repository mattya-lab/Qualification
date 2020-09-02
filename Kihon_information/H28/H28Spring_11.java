import java.util.UUID;
import java.util.ArrayList;
import java.util.List;

class ToDo{
    public enum Priority{ LOW, MIDDLE, HIGH }
    public enum State{ NOT_YET_STARTED, STARTED, DONE }

    private static final String DEADLINE_PATTERN = "\\d{8}|\\d{12}";

    private final String id;
    private String subject;
    private String deadline;
    private Priority priority;
    private State state;

    private ToDo(String subject, String deadline, Priority priority, String id, State state){
	if (!deadline.matches(DEADLINE_PATTERN)) {
	    throw new IllegalArgumentException();
	}
	this.subject = subject;
	this.deadline = deadline;
	this.priority = priority;
	this.id = id;
	this.state = state;
    }
    
    public ToDo(String subject, String deadline, Priority priority){
	this(subject, deadline, priority, UUID.randomUUID().toString(), State.NOT_YET_STARTED);
    }

    public ToDo(ToDo todo){
	this(todo.subject, todo.deadline, todo.priority, todo.id, todo.state);
    }
    
    public String getSubject () { return subject; }
    public String getDeadline () { return deadline; }
    public Priority getPriority () { return priority; }
    public State getState () { return state; }
    public void setState (State state) { this.state = state; }
    public int hashCode () { return id.hashCode(); }
    public boolean equals (Object o) {
	return o instanceof ToDo && ((ToDo) o).id.equals(id);
    }

    public String toString () {
	return String.format("subject: %s, deadline: %s, Priority: %s, State: %s",
			     subject, deadline, priority, state);
    }
}

class ToDoList {
    private List<ToDo> todoList = new ArrayList<ToDo>();
    
    public void add (ToDo todo) {
	if (!todoList.contains(todo)) {
	    todoList.add(new ToDo(todo));
	}
    }
    
    public void update(ToDo todo){
	int index = todoList.indexOf(todo);
	if (index != -1) {
	    todoList.set(index, todo);
	}
    }
    
    public List<ToDo> select(Condition... conditions){
	List<ToDo> result = new ArrayList<ToDo>();
	for (ToDo todo : todoList) {
	    boolean selected = true;
	    for (Condition condition : conditions) {
		selected = condition.test(todo);
		if(!selected) break;
	    }
	    if (selected) {
		result.add(new ToDo(todo));
	    }
	}
	return result;
    }
}

interface Condition {
    boolean test(ToDo todo);
}

public class H28Spring_11 {
    public static void main(String[] args){
	ToDoList list = new ToDoList();
	list.add(new ToDo("Mail Send", "201604181500", ToDo.Priority.HIGH));
	list.add(new ToDo("Hotal Book", "20160420", ToDo.Priority.LOW));
	list.add(new ToDo("Ticket Buy", "20160430", ToDo.Priority.MIDDLE));
	list.add(new ToDo("Report Write", "20160428", ToDo.Priority.HIGH));
	list.add(new ToDo("Room Book", "201605301200", ToDo.Priority.HIGH));
	list.update(new ToDo("PC Buy", "20160531", ToDo.Priority.HIGH));
	for(ToDo todo : list.select()){
	    todo.setState(ToDo.State.STARTED);
	    list.update(todo);
	}

	Condition condition1 = new Condition() {
	    public boolean test(ToDo todo){
		return todo.getDeadline().compareTo("20160501") < 0;
	    }
	};	
	Condition condition2 = new Condition() {
	    public boolean test(ToDo todo){
		return todo.getPriority().equals(ToDo.Priority.HIGH);
	    }
	};
        for(ToDo todo : list.select(condition1, condition2)){
	    System.out.println(todo);

	}
    }
}
