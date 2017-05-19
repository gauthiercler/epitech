%ifndef PERF_EVENT_OPEN
%define PERF_EVENT_OPEN

section .text
    global perf_event_open:function

perf_event_open:
        mov rax, 298
        syscall
        ret

%endif
