import java.util.*;

public class P19 {

    public static void main(String args[]) {
        Calendar start = GregorianCalendar.getInstance();
        start.set(start.MONTH, start.JANUARY);
        start.set(start.DATE, 1);
        start.set(start.YEAR, 1901);
        
        Calendar end = GregorianCalendar.getInstance();
        end.set(end.MONTH, end.DECEMBER);
        end.set(end.DATE, 31);
        end.set(end.YEAR, 2000);
        
        int out = 0;
        while (start.before(end)) {
            if (start.get(start.DAY_OF_WEEK) == start.SUNDAY && 
                            start.get(start.DAY_OF_MONTH) == 1) {
                //System.out.println(start);
                out ++;
            }
            start.add(Calendar.MONTH, 1);
        }
        System.out.println(out);
    }
}