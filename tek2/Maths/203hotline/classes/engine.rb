class Engine

  @runners
  @args
  @compute_mode

  def initialize(compute_mode)

    @compute_mode = compute_mode
    @runners = {
        0 => 0,
        1 => self.method(:run_distributions),
        2 => self.method(:run_simultaneous)
    }

    @args = []
    $*.each do |x|
      @args << x.to_i
    end

    if @compute_mode == 2 && @args[1] > @args[0]
      exit 84
    end

  end

  def run
    @runners[@compute_mode].call
  end

  def run_distributions

    callers = 3500
    call_duration = @args[0]
    time_range = 8.0 * 3600.0
    probability = call_duration / time_range

    puts "Binomial distribution:"
    data = []
    binomial_time_start = Time.now()

    (0..50).map{|x|
      value = x.binomial(callers, probability)
      x <= 25 ? data << value : 0
      $><< "#{x} -> " + '%.3f' % value
      $><< ( ((((x + 1) % 6) == 0) && (x != 0)) || (x == 50) ? "\n" : "\t")
    }

    binomial_time_end = Time.now()
    elapsed_time = (binomial_time_end - binomial_time_start) * 1000.0

    puts "overload: " + '%.1f' % ((1.0 - data.reduce(:+)) * 100.0).to_s + "%"
    puts "computation time: " + '%.2f' % elapsed_time + " ms"

    puts ""

    puts "Poisson distribution:"
    data = []
    poisson_time_start = Time.now()

    (0..50).map{|x|
      value = x.poisson((call_duration / 3600.0 * callers) / 8.0, x)
      x <= 25 ? data << value : 0
      $><< "#{x} -> " + '%.3f' % value
      $><< ( ((((x + 1) % 6) == 0) && (x != 0)) || (x == 50) ? "\n" : "\t")
    }

    poisson_time_end = Time.now()
    elapsed_time = (poisson_time_end - poisson_time_start) * 1000.0

    puts "overload: " + '%.1f' % ((1.0 - data.reduce(:+)) * 100.0).to_s + "%"
    puts "computation time: " + '%.2f' % elapsed_time + " ms"

  end

  def run_simultaneous

    puts "#{@args[1]}-combination of a #{@args[0]} set:"
    puts @args[1].combination(@args[0])

  end

end