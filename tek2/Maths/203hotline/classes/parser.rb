class Parser

  @args

  def initialize(args)
    @args = args;
  end

  def check_nb_args
    if !([1, 2].include? @args.length)
      exit 84
    end
  end

  def check_args_values
    @args.each do |arg|
      if arg !~ /^[0-9]+$/
        exit 84
      end
    end
  end

  def parse
    self.check_nb_args
    self.check_args_values
    @args.length
  end
end
