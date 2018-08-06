object Leap {
  def leapYear(year: Int): Boolean = year match {
    case n if isDivisibleBy(n, 400) => true
    case n if isDivisibleBy(n, 100) => false
    case n if isDivisibleBy(n, 4) => true
    case _ => false
  }

  // Returns if x1 is divisible by x2
  def isDivisibleBy(x1: Int, x2: Int): Boolean = {
    x1 % x2 == 0
  }
}
