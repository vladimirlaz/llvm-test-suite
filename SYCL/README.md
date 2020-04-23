SYCL-related tests directory.

 - External - contains infrastructure for running tests which sources are stored outside of this repository
 - lit - directory containing LIT infra to simplify out-of-box execution.
 - MultiSource - SYCL related tests which depend on multiple source file.
 - SingleSource - SYCL tests wuires single source file.
 - Parallel - Tests which produce high-parallel load on taret device. It is recommended to run such tests in 1 thread.
 - Wimpy - tests used for sunnity testing. Building, executing an dchecks are defined using insource comment with LIT synthax.

