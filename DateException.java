import java.util.Scanner;
import exceptions.InvalidDayException;
import exceptions.InvalidMonthException;

class CurrentDate
{
	private int day,month,year;

	CurrentDate(int day,int month,int year)
	{
		this.day = day;
		this.month = month;
		this.year = year;
	}

	static CurrentDate createDate()
	{
		Scanner sc = new Scanner(System.in);

		try
		{
			System.out.print("Enter the day : ");
			int Day = sc.nextInt();

			if (Day < 1 || Day > 31)
				throw new InvalidDayException(Day);

			System.out.print("Enter the month : ");
			int Month = sc.nextInt();

			if (Month < 1 || Month > 12)
				throw new InvalidMonthException(Month);
			if ((Month == 2 || Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day == 31)
				throw new InvalidDayException(Day,Month);
			if (Month == 2 && Day == 30)
				throw new InvalidDayException(Day,Month);


			System.out.print("Enter the year : ");
			int Year = sc.nextInt();

			if (Year % 4 != 0 && Month == 2 && Day == 29)
				throw new InvalidDayException(Day,Month,Year);



		}

		catch (InvalidDayException ide)
		{
			System.out.println(ide);
			ide.printStackTrace();
		}

		catch (InvalidMonthException ime)
		{
			System.out.println(ime);
			ime.printStackTrace();
		}

		finally
		{
			return new CurrentDate(Day,Month,Year);
		}

		
	}


}


class DateException
{
	public static void main(String[] args)
	{
		CurrentDate date1 = CurrentDate.createDate();
	}
}
