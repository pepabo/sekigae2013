require 'drb/drb'

class Sekigae
  def initialize
    @members ||= ["okkun", "takeo", "gussan", "kitak"]
  end

  def shuffle
    @members.shuffle.join(' | ')
  end
end

DRb.start_service('druby://localhost:54300', Sekigae.new)
loop do
  sleep 1
end
