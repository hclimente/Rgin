.build_path <- function(path) {
    if (.Platform$OS.type == "windows") {
        path <- normalizePath(path)
    if (grepl(' ', path, fixed=TRUE))
        path <- utils::shortPathName(path)
    path <- gsub("\\\\", "/", path)
    }
    path
}

.pkgMk <- function() {
    if (.Platform$OS.type != "windows")
        stop(".pkgMk() expects windows operating system")

    path <- system.file(package="Rgin", "etc", .Platform$r_arch,
                        "Rgin.mk", mustWork=TRUE)
    .build_path(path)
}

.pkgLd <- function() {
    path <- system.file(package="Rgin", "usrlib", .Platform$r_arch,
                        mustWork=TRUE)
    .build_path(path)
}
