program sekigae
  implicit none
  character(len=7),dimension(4) :: chararray
  data chararray/'okkun', 'kitak', 'keoken', 'gussan'/

  call shuffle(chararray)
  write(*,*) chararray
  stop

contains
  subroutine shuffle(a)
    character(len=7),dimension(4), intent(inout) :: a(:)
    character(len=7) :: temp
    integer :: i, randpos, clock, nRand
    real :: r
    integer, allocatable :: seed(:)
    real*8 :: rand(4)

    call random_seed(size = nRand)
    allocate(seed(nRand))
    call system_clock(count = clock)
    seed = clock
    call random_seed(put = seed)

    do i = size(a), 2, -1
       call random_number(r)
       randpos = int(r * i) + 1
       temp = a(randpos)
       a(randpos) = a(i)
       a(i) = temp
    end do
    deallocate (seed)
  end subroutine shuffle
end program sekigae
