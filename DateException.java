import java.util.Scanner;
import exceptions.InvalidDayException;
import exceptions.InvalidMonthException;

class CurrentDate {
    private int day, month, year;

    // Constructor for setting the date
    CurrentDate(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    // Static method to create a CurrentDate object or return null if exception occurs
    static CurrentDate createDate() {
        Scanner sc = new Scanner(System.in);
        int day, month, year;

        try {
            System.out.print("Enter the day: ");
            day = sc.nextInt();

            if (day < 1 || day > 31)
                throw new InvalidDayException(day);

            System.out.print("Enter the month: ");
            month = sc.nextInt();

            if (month < 1 || month > 12)
                throw new InvalidMonthException(month);
            if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
                throw new InvalidDayException(day, month);
            if (month == 2 && day == 30)
                throw new InvalidDayException(day, month);

            System.out.print("Enter the year: ");
            year = sc.nextInt();

            if (year % 4 != 0 && month == 2 && day == 29)
                throw new InvalidDayException(day, month, year);

            // If all validations pass, return the new date object
            return new CurrentDate(day, month, year);

        } catch (InvalidDayException ide) {
            //System.out.println(ide);
            ide.printStackTrace();
        } catch (InvalidMonthException ime) {
            //System.out.println(ime);
            ime.printStackTrace();
        }

        // Return null if any exception occurs
        return null;
    }
}

class DateException 
{
    public static void main(String[] args) 
    {
        // Try to create a date
        CurrentDate date1 = CurrentDate.createDate();

        // Check if the date object was created successfully
        if (date1 == null) 
            System.out.println("Invalid date entered. No date object created.");
        else 
            System.out.println("Date created successfully.");
    }
}
