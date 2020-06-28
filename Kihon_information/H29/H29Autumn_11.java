import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

class TableSorter{
    private Map<String, Comparator<String>> orderMap = new HashMap<String, Comparator<String>>();

    public void putSortOrder(String key, Comparator<String> order){
	orderMap.put(key, order);
    }

    public void sort(String[][] table, final OrderBy[] orderBys){
	Arrays.sort(table, new Comparator<String[]>(){ public int compare(String[] s1, String[] s2){
	    for (OrderBy orderBy : orderBys){
		int order = orderMap.get(orderBy.key).compare(s1[orderBy.col], s2[orderBy.col]);
		if(order != 0){
		    return orderBy.isReversed? -order : order;
		}
	    }
	    return 0;
	}
       });
    }

    public static class OrderBy{
	final String key;
	final int col;
	final boolean isReversed;
	
	public OrderBy(String key, int col){
	    this(key, col, false);
	}
	
	public OrderBy(String key, int col, boolean isReversed){
	    this.key = key;
	    this.col = col;
	    this.isReversed = isReversed;
	}
    }
}

public class H29Autumn_11{
    public static void main(String[] args){
	String [][] data = new String[][]{
	    { "apple", "3", "1,000"},
	    {"cherry", "1", "1,000"},
	    {"banana", "1",   "300"},
	    {"banana", "2", "2,000"},
	    { "apple", "2",   "300"},
	};
	TableSorter sorter = new TableSorter();
	sorter.putSortOrder("lex", new Comparator<String>(){
		public int compare(String o1, String o2){
		    return o1.compareTo(o2);
		}
	    });
	sorter.putSortOrder("num", new Comparator<String>(){
		public int compare(String o1, String o2){
		    return new Integer(o1).compareTo(new Integer(o2));
	        }
	    });
	TableSorter.OrderBy orderBys[];
	orderBys = new TableSorter.OrderBy[2];
	//orderBys[0] = new TableSorter.OrderBy("lex", 0);
	//orderBys[1] = new TableSorter.OrderBy("num", 1, true);
	orderBys[0] = new TableSorter.OrderBy("lex", 2);
	orderBys[1] = new TableSorter.OrderBy("lex", 0);
	sorter.sort(data, orderBys);

	for(String[] row : data){
	    for(String col : row){
		System.out.printf("%s ", col);
	    }
	    System.out.println();
	}
    }
}
