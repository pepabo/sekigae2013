require 'drb/drb'

DRb.start_service
ro = DRbObject.new_with_uri('druby://localhost:54300')
puts ro.shuffle
