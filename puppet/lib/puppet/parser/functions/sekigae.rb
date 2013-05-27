module Puppet::Parser::Functions
  newfunction(:sekigae, type: :rvalue) do |args|
    args.shuffle
  end
end
