whoami := $(shell whoami)
fbasen := top
targs  := $(patsubst %,%.pdf,$(fbasen))

.PHONY: default
default: all 

.PHONY: targs
targs: $(targs)

%.pdf: %.tex $(wildcard *.tex) $(wildcard figure/*.tex) $(wildcard figure/*.eps) figs
	pdflatex $<
	bibtex $*
	pdflatex $<
	pdflatex $<

.PHONY: makefinal
makefinal:
#	sed -i.backup 's/\\DRAFTtrue %control/\\DRAFTfalse %control/' top.tex

.PHONY: makedraft
makedraft:
#	sed -i.backup 's/\DRAFTtrue/%\DRAFTtrue/' top.tex

.PHONY: figs
figs:
	$(MAKE) -C figures

.PHONY: clean
clean: cleanmost
	rm -f $(fbasen).pdf
	$(MAKE) -C figures clean

.PHONY: cleanmost
cleanmost:
	rm -f *~ *.bak \
	$(patsubst %,%.dvi,$(fbasen)) \
	$(patsubst %,%.log,$(fbasen)) \
	$(patsubst %,%.aux,$(fbasen)) \
	$(patsubst %,%.bbl,$(fbasen)) \
	$(patsubst %,%.blg,$(fbasen)) \
	$(patsubst %,%.lox,$(fbasen)) \
	$(patsubst %,%.upa,$(fbasen)) \
	$(patsubst %,%.upb,$(fbasen))

.PHONY: dist-clean
dist-clean: clean
	rm -f library-short.bib library.bib to-be-added.bib

.PHONY: all
all:
	$(MAKE) final

.PHONY: final
final: | makefinal $(targs) cleanmost

.PHONY: draft
draft: | clean makedraft $(targs) cleanmost

