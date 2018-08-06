object SumOfMultiples {
  def sum(factors: Set[Int], limit: Int): Int = limit match {
    case 1 => 0
    case _ => {
      (1 until limit).filter(x => isMultiple(factors, x)).sum
    }
  }

  // returns if b is multiple of any member of factors
  def isMultiple(factors: Set[Int], b: Int): Boolean = {
    factors.exists(f => b % f == 0)
  }
}

