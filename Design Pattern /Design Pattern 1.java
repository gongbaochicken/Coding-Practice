Design Patterns

1. MVC Pattern
/*
MVC mainly is used for separating the application
from the user data. 
*/

// Pseudocode
public class Model{
	//Program states, variables, etc
}

public class View{
	//contains UI
}

public class Control{
	//waits for inputes from view, and apply to model
	//waits for model updates and then change the view
}

2. Listner Design Pattern
/*
Listner Design Pattern is used when a branch of "listeners"
wait to be notified, when a certain event happen. 
*/ 
//Pseudocode

public class Listner{
	public static void listener(){
		Event event = new Event();
		EventListner eventListner = new EventListner();
		event.addListner(eventListner);
	}
}

3. Singleton Pattern
/*
The singleton pattern is used to maintain a single instance
of an object. The key is that it has the private constructors.
When an instance of singleton object is needed, call "getInstance".
*/

public class Singleton{
	private static final Singleton instance;

	static{
		instance = new Singleton();
	}

	public static Singleton getInstance(){
		return instance;
	}

	private Singleton(){
		
	}
}

/*For static final, all instances share the same value, and 
can't be altered after first initialized.*/





