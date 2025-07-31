#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create scene for the board
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->boardView->setScene(scene);
    ui->boardView->setRenderHint(QPainter::Antialiasing);

    // Define sizes
    const int squareSize = 60;  // Size of each square
    const int margin = 30;      // Margin for labels

    // Draw 8x8 chessboard with offset for margins
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QGraphicsRectItem *square = new QGraphicsRectItem(
                margin + col * squareSize,
                margin + row * squareSize,
                squareSize,
                squareSize
                );
            QColor color = (row + col) % 2 == 0 ? QColor(240, 217, 181) : QColor(181, 136, 99);  // Light and dark squares
            square->setBrush(color);
            scene->addItem(square);
        }
    }

    // Add file labels (A-H) at the bottom
    QString files = "ABCDEFGH";
    QFont labelFont("Arial", 12, QFont::Bold);
    for (int col = 0; col < 8; ++col) {
        QGraphicsTextItem *fileLabel = new QGraphicsTextItem(files[col]);
        fileLabel->setFont(labelFont);
        fileLabel->setDefaultTextColor(QColor(0, 0, 0));  // Black text
        // Position: centered below the board
        qreal x = margin + col * squareSize + squareSize / 2 - fileLabel->boundingRect().width() / 2;
        qreal y = margin + 8 * squareSize;  // Below the last row
        fileLabel->setPos(x, y);
        scene->addItem(fileLabel);
    }

    // Add rank labels (1-8) on the left side
    for (int row = 0; row < 8; ++row) {
        QGraphicsTextItem *rankLabel = new QGraphicsTextItem(QString::number(8 - row));  // 8 at top, 1 at bottom
        rankLabel->setFont(labelFont);
        rankLabel->setDefaultTextColor(QColor(0, 0, 0));
        // Position: centered to the left of the board
        qreal x = margin - rankLabel->boundingRect().width();  // Left of margin
        qreal y = margin + row * squareSize + squareSize / 2 - rankLabel->boundingRect().height() / 2;
        rankLabel->setPos(x, y);
        scene->addItem(rankLabel);
    }

    // Adjust scene rect to include margins
    scene->setSceneRect(0, 0, margin * 2 + 8 * squareSize, margin * 2 + 8 * squareSize);

    // Example: Add a pawn (load your piece images)
    // QPixmap whitePawn(":/images/white_pawn.png");
    // QGraphicsPixmapItem *pawn = new QGraphicsPixmapItem(whitePawn.scaled(squareSize, squareSize));
    // pawn->setPos(margin + 0 * squareSize, margin + 6 * squareSize);  // a2 position (row 6 is rank 2)
    // scene->addItem(pawn);

    // TODO: Implement mouse events for dragging pieces, UCI integration, etc.
}

MainWindow::~MainWindow()
{
    delete ui;
}
