class Integer

  def factorial
    (2..self).reduce(1, :*)
  end

  def combination(n)
    if self > n / 2
      n.choose(n - self)
    else
      n.choose(self)
    end
  end

  def choose(k)
    pTop = (self-k+1 .. self).inject(1, &:*)
    pBottom = (2 .. k).inject(1, &:*)
    pTop / pBottom
  end

  def binomial(n, p)
    self.combination(n) * (p ** self) * ((1 - p) ** (n - self))
  end

  def poisson(l, k)
    Math.exp(-1.0 * l) * ((l ** k) / k.factorial)
  end

end