DEPENDS += "openssl virtual/docker "
RDEPENDS:${PN} += "docker "

SRC_URI +="file://0001-Change-panic-strategy-to-unwind.patch"

FILES_SOLIBSDEV = ""
SOLIBS = ".so"
INSANE_SKIP_${PN} += "dev-so"

do_install:append () {
    install -d ${D}${libdir}
    install -m 755 ${WORKDIR}/build/target/${RUST_TARGET_SYS}/release/libaziot_keys.so ${D}${libdir}/libaziot_keys.so
}
