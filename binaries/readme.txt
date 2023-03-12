
Фикс детекции EAX в бинарниках скомпилированных из исходников v2 (проверено на ТЧ 1.0007).


1.В bin засунуть eax.dll, OpenAL32.dll, wrap_oal.dll из этого архива.
(Они уже пропатчены на Generic Softwarz и Generic Hardwarz вместо Generic Software и Generic Hardware).

2.Запустить игру, смотреть в логе, чтобы было:
* sound: EAX 2.0 extension: present
* sound: EAX 2.0 deferred: present 

4.После этого, на уровнях должны заработать звуковые зоны, если есть.



idea by Macron
оптимизации by vlad_54rus