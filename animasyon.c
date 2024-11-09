#include <GL/glut.h>

float angle = 0.0f;

void initGL() {
    glEnable(GL_DEPTH_TEST); // Derinlik testi etkinleştir
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Ekranı ve derinlik tamponunu temizle
    glLoadIdentity(); // Model görünüm matrisini sıfırla

    glTranslatef(0.0f, 0.0f, -5.0f); // Küpü ekranın ortasına çek
    glRotatef(angle, 1.0f, 1.0f, 0.0f); // Küpü X ve Y eksenleri etrafında döndür

    glBegin(GL_QUADS); // Küpü oluştur

    // Ön yüz (kırmızı)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, 1.0f);

    // Arka yüz (yeşil)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Üst yüz (mavi)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);

    // Alt yüz (sarı)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    // Sağ yüz (turuncu)
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);

    // Sol yüz (mor)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    glEnd();

    glutSwapBuffers(); // Çift tamponlama için tamponları değiştir
}

void timer(int value) {
    angle += 2.0f; // Dönüş hızını artır
    if (angle > 360.0f) {
        angle -= 360.0f;
    }
    glutPostRedisplay(); // Ekranı yeniden çiz
    glutTimerFunc(16, timer, 0); // 16 ms sonra timer fonksiyonunu tekrar çağır
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Güzelleştirilmiş Küp");
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    initGL();
    glutMainLoop();
    return 0;
}