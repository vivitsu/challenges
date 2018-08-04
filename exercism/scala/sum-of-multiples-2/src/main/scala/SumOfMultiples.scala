object SumOfMultiples {
  def sum(factors: Set[Int], limit: Int): Int = limit match {
    case 1 => 0
    case _ => {
      val xs = List.range(1, limit)
      xs.filter(x => isMultiple(factors, x)).foldLeft(0)(_ + _)
    }
  }

  // returns if b is multiple of any member of factors
  def isMultiple(factors: Set[Int], b: Int): Boolean = {
    var res = false
    for (f <- factors) {
      res |= (b % f == 0)
    }
    res
  }
}

