##
## Makefile for Makefile in /home/gogo/rendu/tek2/asm_minilibc
##
## Made by Gauthier Cler
## Login   <gauthier.cler@epitech.eu>
##
## Started on  Wed Mar  1 09:44:20 2017 Gauthier Cler
## Last update Wed Mar 22 19:10:56 2017 Gauthier Cler
##

NAME	=		libasm.so

FLAGS	=		-f elf64

SRCS	=		srcs/strlen.s \
			srcs/strcmp.s \
			srcs/strncmp.s \
			srcs/tolower.s \
			srcs/strcasecmp.s \
			srcs/memset.s \
			srcs/memcpy.s \
			srcs/memmove.s \
			srcs/rindex.s \
			srcs/strchr.s \
			srcs/strpbrk.s \
			srcs/strcspn.s \
			srcs/strstr.s \
                        srcs/accept4.s \
                        srcs/accept.s \
                        srcs/access.s \
                        srcs/acct.s \
                        srcs/add_key.s \
                        srcs/adjtimex.s \
                        srcs/afs_syscall.s \
                        srcs/alarm.s \
                        srcs/arch_prctl.s \
                        srcs/bind.s \
                        srcs/bpf.s \
                        srcs/brk.s \
                        srcs/capget.s \
                        srcs/capset.s \
                        srcs/chdir.s \
                        srcs/chmod.s \
                        srcs/chown.s \
                        srcs/chroot.s \
                        srcs/clock_getres.s \
                        srcs/clock_gettime.s \
                        srcs/clock_nanosleep.s \
                        srcs/clock_settime.s \
                        srcs/clone.s \
                        srcs/close.s \
                        srcs/connect.s \
                        srcs/create_module.s \
                        srcs/creat.s \
                        srcs/delete_module.s \
                        srcs/dup2.s \
                        srcs/dup3.s \
                        srcs/dup.s \
                        srcs/epoll_create1.s \
                        srcs/epoll_create.s \
                        srcs/epoll_ctl.s \
                        srcs/epoll_pwait.s \
                        srcs/epoll_wait.s \
                        srcs/eventfd2.s \
                        srcs/eventfd.s \
                        srcs/execve.s \
                        srcs/exit_group.s \
                        srcs/exit.s \
                        srcs/faccessat.s \
                        srcs/fadvise64.s \
                        srcs/fallocate.s \
                        srcs/fanotify_init.s \
                        srcs/fanotify_mark.s \
                        srcs/fchdir.s \
                        srcs/fchmodat.s \
                        srcs/fchmod.s \
                        srcs/fchownat.s \
                        srcs/fchown.s \
                        srcs/fcntl.s \
                        srcs/fdatasync.s \
                        srcs/finit_module.s \
                        srcs/flock.s \
                        srcs/fork.s \
                        srcs/fstatfs.s \
                        srcs/fstat.s \
                        srcs/fsync.s \
                        srcs/ftruncate.s \
                        srcs/futex.s \
                        srcs/futimesat.s \
                        srcs/getcpu.s \
                        srcs/getcwd.s \
                        srcs/getdents64.s \
                        srcs/getdents.s \
                        srcs/getegid.s \
                        srcs/geteuid.s \
                        srcs/getgid.s \
                        srcs/getgroups.s \
                        srcs/getitimer.s \
                        srcs/get_kernel_syms.s \
                        srcs/get_mempolicy.s \
                        srcs/getpeername.s \
                        srcs/getpgid.s \
                        srcs/getpgrp.s \
                        srcs/getpid.s \
                        srcs/getpmsg.s \
                        srcs/getppid.s \
                        srcs/getpriority.s \
                        srcs/getrandom.s \
                        srcs/getresgid.s \
                        srcs/getresuid.s \
                        srcs/getrlimit.s \
                        srcs/get_robust_list.s \
                        srcs/getrusage.s \
                        srcs/getsid.s \
                        srcs/getsockname.s \
                        srcs/getsockopt.s \
                        srcs/get_thread_area.s \
                        srcs/gettid.s \
                        srcs/gettimeofday.s \
                        srcs/getuid.s \
                        srcs/init_module.s \
                        srcs/inotify_add_watch.s \
                        srcs/inotify_init1.s \
                        srcs/inotify_init.s \
                        srcs/inotify_rm_watch.s \
                        srcs/io_cancel.s \
                        srcs/ioctl.s \
                        srcs/io_destroy.s \
                        srcs/io_getevents.s \
                        srcs/ioperm.s \
                        srcs/iopl.s \
                        srcs/ioprio_get.s \
                        srcs/ioprio_set.s \
                        srcs/io_setup.s \
                        srcs/io_submit.s \
                        srcs/kcmp.s \
                        srcs/kexec_file_load.s \
                        srcs/kexec_load.s \
                        srcs/keyctl.s \
                        srcs/kill.s \
                        srcs/lchown.s \
                        srcs/linkat.s \
                        srcs/link.s \
                        srcs/listen.s \
                        srcs/lookup_dcookie.s \
                        srcs/lseek.s \
                        srcs/lstat.s \
                        srcs/madvise.s \
                        srcs/mbind.s \
                        srcs/membarrier.s \
                        srcs/memfd_create.s \
                        srcs/migrate_pages.s \
                        srcs/mincore.s \
                        srcs/mkdirat.s \
                        srcs/mkdir.s \
                        srcs/mknodat.s \
                        srcs/mknod.s \
                        srcs/mlock2.s \
                        srcs/mlockall.s \
                        srcs/mlock.s \
                        srcs/mmap.s \
                        srcs/modify_ldt.s \
                        srcs/mount.s \
                        srcs/move_pages.s \
                        srcs/mprotect.s \
                        srcs/mq_getsetattr.s \
                        srcs/mq_notify.s \
                        srcs/mq_open.s \
                        srcs/mq_timedreceive.s \
                        srcs/mq_timedsend.s \
                        srcs/mq_unlink.s \
                        srcs/mremap.s \
                        srcs/msgctl.s \
                        srcs/msgget.s \
                        srcs/msgrcv.s \
                        srcs/msgsnd.s \
                        srcs/msync.s \
                        srcs/munlockall.s \
                        srcs/munlock.s \
                        srcs/munmap.s \
                        srcs/name_to_handle_at.s \
                        srcs/nanosleep.s \
                        srcs/newfstatat.s \
                        srcs/nfsservctl.s \
                        srcs/openat.s \
                        srcs/open_by_handle_at.s \
                        srcs/open.s \
                        srcs/pause.s \
                        srcs/perf_event_open.s \
                        srcs/personality.s \
                        srcs/pipe2.s \
                        srcs/pipe.s \
                        srcs/pivot_root.s \
                        srcs/poll.s \
                        srcs/ppoll.s \
                        srcs/prctl.s \
                        srcs/pread64.s \
                        srcs/preadv.s \
                        srcs/prlimit64.s \
                        srcs/process_vm_readv.s \
                        srcs/process_vm_writev.s \
                        srcs/pselect6.s \
                        srcs/ptrace.s \
                        srcs/putpmsg.s \
                        srcs/pwrite64.s \
                        srcs/pwritev.s \
                        srcs/query_module.s \
                        srcs/quotactl.s \
                        srcs/readahead.s \
                        srcs/readlinkat.s \
                        srcs/readlink.s \
                        srcs/read.s \
                        srcs/readv.s \
                        srcs/reboot.s \
                        srcs/recvfrom.s \
                        srcs/recvmmsg.s \
                        srcs/recvmsg.s \
                        srcs/remap_file_pages.s \
                        srcs/renameat2.s \
                        srcs/renameat.s \
                        srcs/rename.s \
                        srcs/request_key.s \
                        srcs/restart_syscall.s \
                        srcs/rmdir.s \
                        srcs/rt_sigaction.s \
                        srcs/rt_sigpending.s \
                        srcs/rt_sigprocmask.s \
                        srcs/rt_sigqueueinfo.s \
                        srcs/rt_sigreturn.s \
                        srcs/rt_sigsuspend.s \
                        srcs/rt_sigtimedwait.s \
                        srcs/rt_tgsigqueueinfo.s \
                        srcs/sched_getaffinity.s \
                        srcs/sched_getattr.s \
                        srcs/sched_getparam.s \
                        srcs/sched_get_priority_max.s \
                        srcs/sched_get_priority_min.s \
                        srcs/sched_getscheduler.s \
                        srcs/sched_rr_get_interval.s \
                        srcs/sched_setaffinity.s \
                        srcs/sched_setattr.s \
                        srcs/sched_setparam.s \
                        srcs/sched_setscheduler.s \
                        srcs/sched_yield.s \
                        srcs/seccomp.s \
                        srcs/security.s \
                        srcs/select.s \
                        srcs/semctl.s \
                        srcs/semget.s \
                        srcs/semop.s \
                        srcs/semtimedop.s \
                        srcs/sendfile.s \
                        srcs/sendmmsg.s \
                        srcs/sendmsg.s \
                        srcs/sendto.s \
                        srcs/setdomainname.s \
                        srcs/setfsgid.s \
                        srcs/setfsuid.s \
                        srcs/setgid.s \
                        srcs/setgroups.s \
                        srcs/sethostname.s \
                        srcs/setitimer.s \
                        srcs/set_mempolicy.s \
                        srcs/setns.s \
                        srcs/setpgid.s \
                        srcs/setpriority.s \
                        srcs/setregid.s \
                        srcs/setresgid.s \
                        srcs/setresuid.s \
                        srcs/setreuid.s \
                        srcs/setrlimit.s \
                        srcs/set_robust_list.s \
                        srcs/setsid.s \
                        srcs/setsockopt.s \
                        srcs/set_thread_area.s \
                        srcs/set_tid_address.s \
                        srcs/settimeofday.s \
                        srcs/setuid.s \
                        srcs/shmat.s \
                        srcs/shmctl.s \
                        srcs/shmdt.s \
                        srcs/shmget.s \
                        srcs/shutdown.s \
                        srcs/sigaltstack.s \
                        srcs/signalfd4.s \
                        srcs/signalfd.s \
                        srcs/socketpair.s \
                        srcs/socket.s \
                        srcs/splice.s \
                        srcs/statfs.s \
                        srcs/stat.s \
                        srcs/swapoff.s \
                        srcs/swapon.s \
                        srcs/symlinkat.s \
                        srcs/symlink.s \
                        srcs/sync_file_range.s \
                        srcs/syncfs.s \
                        srcs/sync.s \
                        srcs/_sysctl.s \
                        srcs/sysfs.s \
                        srcs/sysinfo.s \
                        srcs/syslog.s \
                        srcs/tee.s \
                        srcs/tgkill.s \
                        srcs/timer_create.s \
                        srcs/timer_delete.s \
                        srcs/timerfd_create.s \
                        srcs/timerfd_gettime.s \
                        srcs/timerfd_settime.s \
                        srcs/timer_getoverrun.s \
                        srcs/timer_gettime.s \
                        srcs/timer_settime.s \
                        srcs/time.s \
                        srcs/tkill.s \
                        srcs/truncate.s \
                        srcs/tuxcall.s \
                        srcs/umask.s \
                        srcs/umount2.s \
                        srcs/uname.s \
                        srcs/unlinkat.s \
                        srcs/unlink.s \
                        srcs/unshare.s \
                        srcs/uselib.s \
                        srcs/ustat.s \
                        srcs/utimensat.s \
                        srcs/utime.s \
                        srcs/utimes.s \
                        srcs/vfork.s \
                        srcs/vhangup.s \
                        srcs/vmsplice.s \
                        srcs/vserver.s \
                        srcs/wait4.s \
                        srcs/waitid.s \
                        srcs/write.s \
                        srcs/writev.s

OBJS	=		$(SRCS:.s=.o)

ASM	=		nasm

AS	=		$(ASM) $(FLAGS)

all: $(NAME)

$(NAME): $(OBJS)
	ld -fPIC -shared -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
