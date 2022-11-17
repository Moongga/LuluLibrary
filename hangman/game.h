#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <windows.h>
using namespace sf;

/// <summary>
/// method that makes necessary textures for second screen(game scene)
/// In this method we load game scene background and buttons into window. Also we check mouse position and change uncursored button images to cursored
/// </summary>
/// <param name="window"></param>
void game(RenderWindow& window)
{
    /// <summary>
    /// textures for keyboard and background. each russian letter texture named like its transcription in english. Each texture will include its letter image
    /// </summary>
    /// <param name="window"></param>
    Texture Bg_tx;
    Texture A_tx, B_tx, V_tx, G_tx,
        D_tx, YE_tx, YO_tx, ZH_tx, Z_tx,
        I_tx, Y_tx, K_tx, L_tx, M_tx, N_tx,
        O_tx, P_tx, R_tx, S_tx, T_tx,
        U_tx, F_tx, H_tx, C_tx, CH_tx,
        SH_tx, SHsoft_tx, EU_tx, SOFT_tx,
        STRONG_tx, E_tx, YU_tx, YA_tx;

    /// <summary>
    /// Here we are loading uncursored letter images to the btn textures first time
    /// </summary>
    /// <param name="window"></param>
    Bg_tx.loadFromFile("images/game_scene.png");
    A_tx.loadFromFile("images/keyboard/uncursored/a.png");
    B_tx.loadFromFile("images/keyboard/uncursored/b.png");
    V_tx.loadFromFile("images/keyboard/uncursored/v.png");
    G_tx.loadFromFile("images/keyboard/uncursored/g.png");
    D_tx.loadFromFile("images/keyboard/uncursored/d.png");
    YE_tx.loadFromFile("images/keyboard/uncursored/ye.png");
    YO_tx.loadFromFile("images/keyboard/uncursored/yo.png");
    ZH_tx.loadFromFile("images/keyboard/uncursored/zh.png");
    Z_tx.loadFromFile("images/keyboard/uncursored/z.png");
    I_tx.loadFromFile("images/keyboard/uncursored/i.png");
    Y_tx.loadFromFile("images/keyboard/uncursored/y.png");
    K_tx.loadFromFile("images/keyboard/uncursored/k.png");
    L_tx.loadFromFile("images/keyboard/uncursored/l.png");
    M_tx.loadFromFile("images/keyboard/uncursored/m.png");
    N_tx.loadFromFile("images/keyboard/uncursored/n.png");
    O_tx.loadFromFile("images/keyboard/uncursored/o.png");
    P_tx.loadFromFile("images/keyboard/uncursored/p.png");
    R_tx.loadFromFile("images/keyboard/uncursored/r.png");
    S_tx.loadFromFile("images/keyboard/uncursored/s.png");
    T_tx.loadFromFile("images/keyboard/uncursored/t.png");
    U_tx.loadFromFile("images/keyboard/uncursored/u.png");
    F_tx.loadFromFile("images/keyboard/uncursored/f.png");
    H_tx.loadFromFile("images/keyboard/uncursored/h.png");
    C_tx.loadFromFile("images/keyboard/uncursored/c.png");
    CH_tx.loadFromFile("images/keyboard/uncursored/ch.png");
    SH_tx.loadFromFile("images/keyboard/uncursored/sh.png");
    SHsoft_tx.loadFromFile("images/keyboard/uncursored/sh_soft.png");
    EU_tx.loadFromFile("images/keyboard/uncursored/eu.png");
    SOFT_tx.loadFromFile("images/keyboard/uncursored/soft.png");
    STRONG_tx.loadFromFile("images/keyboard/uncursored/strong.png");
    E_tx.loadFromFile("images/keyboard/uncursored/e.png");
    YU_tx.loadFromFile("images/keyboard/uncursored/yu.png");
    YA_tx.loadFromFile("images/keyboard/uncursored/ya.png");

    /// <summary>
    /// Here we make sprite on each texture in the method
    /// </summary>
    /// <param name="window"></param>
    Sprite A(A_tx), B(B_tx), V(V_tx), G(G_tx), D(D_tx), YE(YE_tx), YO(YO_tx), ZH(ZH_tx), Z(Z_tx),
        I(I_tx), Y(Y_tx), K(K_tx), L(L_tx), M(M_tx), N(N_tx), O(O_tx), P(P_tx), R(R_tx), S(S_tx),
        T(T_tx), U(U_tx), F(F_tx), H(H_tx), C(C_tx), CH(CH_tx), SH(SH_tx), SHsoft(SHsoft_tx), EU(EU_tx),
        SOFT(SOFT_tx), STRONG(STRONG_tx), E(E_tx), YU(YU_tx), YA(YA_tx);
    Sprite Bg(Bg_tx);

    bool isMenu = 1;
    int menuNum = 0;
    Bg.setPosition(0, 0);
    while (isMenu)
    {
        /// <summary>
        /// Here we are loading uncursored letter images to the btn textures second time, so every time mouse leaves button, it becomes uncursored again
        /// </summary>
        Bg_tx.loadFromFile("images/game_scene.png");
        A_tx.loadFromFile("images/keyboard/uncursored/a.png");
        B_tx.loadFromFile("images/keyboard/uncursored/b.png");
        V_tx.loadFromFile("images/keyboard/uncursored/v.png");
        G_tx.loadFromFile("images/keyboard/uncursored/g.png");
        D_tx.loadFromFile("images/keyboard/uncursored/d.png");
        YE_tx.loadFromFile("images/keyboard/uncursored/ye.png");
        YO_tx.loadFromFile("images/keyboard/uncursored/yo.png");
        ZH_tx.loadFromFile("images/keyboard/uncursored/zh.png");
        Z_tx.loadFromFile("images/keyboard/uncursored/z.png");
        I_tx.loadFromFile("images/keyboard/uncursored/i.png");
        Y_tx.loadFromFile("images/keyboard/uncursored/k.png");
        K_tx.loadFromFile("images/keyboard/uncursored/l.png");
        L_tx.loadFromFile("images/keyboard/uncursored/m.png");
        M_tx.loadFromFile("images/keyboard/uncursored/n.png");
        N_tx.loadFromFile("images/keyboard/uncursored/o.png");
        O_tx.loadFromFile("images/keyboard/uncursored/p.png");
        P_tx.loadFromFile("images/keyboard/uncursored/r.png");
        R_tx.loadFromFile("images/keyboard/uncursored/s.png");
        S_tx.loadFromFile("images/keyboard/uncursored/t.png");
        T_tx.loadFromFile("images/keyboard/uncursored/u.png");
        U_tx.loadFromFile("images/keyboard/uncursored/f.png");
        F_tx.loadFromFile("images/keyboard/uncursored/h.png");
        H_tx.loadFromFile("images/keyboard/uncursored/h.png");
        C_tx.loadFromFile("images/keyboard/uncursored/c.png");
        CH_tx.loadFromFile("images/keyboard/uncursored/ch.png");
        SH_tx.loadFromFile("images/keyboard/uncursored/sh.png");
        SHsoft_tx.loadFromFile("images/keyboard/uncursored/sh_soft.png");
        EU_tx.loadFromFile("images/keyboard/uncursored/eu.png");
        SOFT_tx.loadFromFile("images/keyboard/uncursored/soft.png");
        STRONG_tx.loadFromFile("images/keyboard/uncursored/strong.png");
        E_tx.loadFromFile("images/keyboard/uncursored/e.png");
        YU_tx.loadFromFile("images/keyboard/uncursored/yu.png");
        YA_tx.loadFromFile("images/keyboard/uncursored/ya.png");

        /// <summary>
        /// Here we set position for each letter sprite
        /// </summary>
        A.setPosition(668, 277); B.setPosition(720, 277); V.setPosition(777, 277); G.setPosition(826, 277); D.setPosition(875, 277);
        /*E.setPosition(); YO.setPosition(); ZH.setPosition(); Z.setPosition(); I.setPosition();
        Y.setPosition(); K.setPosition(); L.setPosition(); M.setPosition(); N.setPosition();
        O.setPosition(); P.setPosition(); R.setPosition(); S.setPosition(); T.setPosition();
        U.setPosition(); F.setPosition(); H.setPosition(); C.setPosition(); CH.setPosition();
        SH.setPosition(); SHsoft.setPosition(); EU.setPosition(); SOFT.setPosition(); STRONG.setPosition();
        E.setPosition(); YU.setPosition(); YA.setPosition();*/

        /// <summary>
        /// here we display all textures
        /// </summary>
        window.draw(Bg);
        window.draw(A);
        window.draw(B);
        window.draw(V);
        window.draw(G);
        window.draw(D);
        window.draw(E);

        window.display();
    }
    if (IntRect(668, 277, 1000, 1000).contains(Mouse::getPosition(window)))
    {
        A_tx.loadFromFile("images/keyboard/uncursored/i.png");
        menuNum = 1;
    }
}
