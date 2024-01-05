@echo off

if "%1"=="_chk_" shift

rem --- Konfiguracja ocen.bat ---
rem W przypadku opracowania wlasnego zestawu testow nalezy zmienic
rem zawartosc zmiennej TESTS a testy zabpiowac do kataloguw IN\, OUT\
rem nazwy testow powinny analogiczne do przykladowych

if "%1"=="kol" goto kol
if "%1"=="KOL" goto kol
if "%1"=="ply" goto ply
if "%1"=="PLY" goto ply
if "%1"=="poc" goto poc
if "%1"=="POC" goto poc
if "%1"=="wyp" goto wyp
if "%1"=="WYP" goto wyp
if "%1"=="zbo" goto zbo
if "%1"=="ZBO" goto zbo


set T=%1
goto end

:kol
set I=kol
set T=0 1 2 3
set C=bin\cmp.exe
goto end
:ply
set I=ply
set T=0 1 2 3
set C=bin\cmp.exe
goto end
:poc
set I=poc
set T=0 1 2
set C=bin\cmp.exe
goto end
:wyp
set I=wyp
set T=201 202 203 204 205 206 207 208 209 210 211 212 213 214 215 216 217 218 219 220 221 222 223 224 225 226 227 228 229 230 231 232 233 234 235 236 237 238 239 240 241 242 243 244 245 246 247 248 249 250 251 252 253 254 255 256 257 258 259 260 261 262 263 264 265 266 267 268 269 270 271 272 273 274 275 276 277 278 279 280 281 282 283 284 285 286 287 288 289 290 291 292 293 294 295 296 297 298 299 300 301 302 303 304 305 306 307 308 309 310 311 312 313 314 315 316 317 318 319 320 321 322 323 324 325 326 327 328 329 330 331 332 333 334 335 336 337 338 339 340 341 342 343 344 345 346 347 348 349 350 351 352 353 354 355 356 357 358 359 360 361 362 363 364 365 366 367 368 369 370 371 372 373 374 375 376 377 378 379 380 381 382 383 384 385 386 387 388 389 390 391 392 393 394 395 396 397 398 399 400 
set C=bin\cmp.exe
goto end
:zbo
set I=zbo
set T=0 1 2
set C=bin\cmp.exe
goto end


rem --- Koniec konfiguracji

:end

if "%C%"=="" goto def_chk
goto new_chk
:def_chk
set C=bin\cmp.exe
:new_chk

:real_end
